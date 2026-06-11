#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define MOD 1000000007

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli num,lli base) {
  lli ans = 1;
  while(base>0) {
    if(base&1)
      ans = mul(ans, num);

    num = mul(num, num);
    base >>= 1;
  }

  return ans;
}

lli ceil(lli a, lli d) {
  if(a%d)
    return a/d + 1;
  return a/d;
}

void solve() {
  lli a, b, c, d;
  cin >> a >> b >> c >> d;
  lli total = b-a+1;
  lli factor_c = 0, factor_d = 0, factor_cd = 0;
  if(b-ceil(a,c)*c >= 0) {
    factor_c = (b-ceil(a, c)*c)/c + 1;
  }

  if((b-ceil(a, d)*d) >= 0) {
    factor_d = (b-ceil(a, d)*d)/d + 1;
  }

  c=c*d/__gcd(c, d);

  if(b-ceil(a,c)*c >= 0) {
    factor_cd = (b-ceil(a, c)*c)/c + 1;
  }

  factor_c = max(factor_c, 0LL);
  factor_d = max(factor_d, 0LL);
  factor_cd = max(factor_cd, 0LL);

  //cout << factor_c << " " << factor_d << " " << factor_cd << endl;
  cout << total - factor_c - factor_d + factor_cd << endl;
  
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

