#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
//#include <boost/foreach.hpp>
//#include <boost/range/algorithm.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define ll long long
#define Sort(v) sort(all(v))
//#define INF 1e9
#define LINF (1LL<<40)
#define END return 0
#define pb push_back
#define se second
#define fi first
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define MP make_pair
#define int long long
#define umap unordered_map 
#define re0 return 0
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 int dx[]={0,1,0,-1};
 int dy[]={1,0,-1,0};
//typedef pair<int,int> P;

const long long MOD=1000000007LL;
bool isupper(char c){if('A'<=c&&c<='Z')return 1;return 0;}
bool islower(char c){if('a'<=c&&c<='z')return 1;return 0;}
bool isnumber(char c){return ('0'<=c&&c<='9');}
bool isalpha(char c){return (isupper(c)||islower(c));}
bool is_kaibun(string s){string rs = s;reverse(all(rs));if(s == rs)return true;else return false;}


template<typename T> 
void printv(vector<T> v, bool is_endl=true){
    for(int i=0;i<v.size();i++){
        if(i)cout<<" ";
        cout<<v[i];
    }
    if(is_endl)cout<<endl;
}
int INF=1e18;

template<typename T>
void printendl(vector<T> v){
    for(auto date:v)cout<<date<<endl;
}

template<typename T>
void printvv(vector<vector<T>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(j)cout<<" ";
            cout<<v[i][j];
        }
        cout<<endl;
    }
}
struct Point{
    int x,y,num;

    double e_dis(Point other){
        return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
    }
};

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

bool isPrime(int x){
  if(x==1)return 0;
  if(x==2)return 1;
  if(x%2==0)return 0;
  for(int i=3;i*i<=x;i++)if(x%i==0)return 0;
  return 1;
}

//スプリット関数
//split(文字列変数,区切りたい文字);
vector<string> split(string s, char c){
    if(s[s.size()-1]!=c)s+=c;
    vector<string> v;
    int pos=0;
    rep(i,0,s.size()){
        if(s[i]==c){
            v.push_back(s.substr(pos,i-pos));
            pos=i+1;
        }
        if(i==s.size()-1 && s.substr(pos,i-pos)!="")v.push_back(s.substr(pos,i-pos));
    }
    return v;
}

int f(int x){
    return (3*x*x+x)/2;
}

signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> va(a),vb(b);
    rep(i,0,a)cin>>va[i];
    rep(i,0,b)cin>>vb[i];
    int ans=1e9;
    rep(i,0,c){
        int x,y,t;
        cin>>x>>y>>t;
        x--; y--;
        ans=min(ans, max(0LL,va[x]+vb[y]-t));
    }
    int mia=*min_element(all(va));
    int mib=*min_element(all(vb));
    ans=min(ans, mia+mib);
    cout<<ans<<endl;




    
    
    

    


}

/*


*/