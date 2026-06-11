#include <cstddef>
#include <iostream>
#include <vector>
#include <set>

#include <signal.h>
#define BOOST_STACKTRACE_USE_ADDR2LINE
#ifdef DEBUG
#include <boost/stacktrace.hpp>
#endif

#define rep(i, n) for (size_t i = 0; i < n; ++i)
#define rev(i, n) for (size_t i = n - 1; i < n; --i)
#define as static_cast
typedef long long ll;
using namespace std;

void handler(int signum) {
  ::signal(signum, SIG_DFL);
#ifdef DEBUG
  cout << boost::stacktrace::stacktrace();
#endif
  ::raise(SIGABRT);
}

int main(int, char const *[])
{
  ::signal(SIGSEGV, &handler);
  ::signal(SIGABRT, &handler);

  size_t n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  ll ans=0;
  set<size_t> s;
  vector<size_t> ix(n);
  rep(i, n) ix[as<size_t>(p[i]-1)]=i;
  rev (j, n) {
    size_t i=ix[j];
    ll c=0;

    s.insert(i);
    int w,x,y,z;

    { // find w, x
      vector<int> wx(2, -1);
      auto it=s.find(i);
      rev(k, 2) {
        if (it == s.begin()) break;
        --it;
        wx[k]=as<int>(*it);
      }
      w=wx[0];x=wx[1];
    }

    { // find y, z
      vector<int> yz(2, as<int>(n));
      auto it=s.find(i);
      rep(k, 2) {
        ++it;
        if (it == s.end()) break;
        yz[k]=as<int>(*it);
      }
      y=yz[0];z=yz[1];
    }

    c=(x-w)*(y-as<int>(i))+(as<int>(i)-x)*(z-y);
    ans+=as<int>(j+1)*c;
  }

  cout << ans << endl;
  return 0;
}
