#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define in insert
#define er erase
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
using namespace std;
typedef vector <int> vi;
typedef vector <vector<int>> vii;
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
typedef long double ld;

const long double PI=3.141592653589793238462643383279502884;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int main(){
    fast;
    ll i;
    string s0;
    cin>>s0;
    ll s=0,k=0,s1=0,m1=-1,m2=0;
    i=0;
    char c=s0[0];
    k=1;
    int sost=1;
    if (s0[0]=='<'){
        sost=0;
    }
    while (i<s0.length()){
        i++;
        while (s0[i]==c&&i<s0.length()){
            k++;
            i++;
        }
        s+=k*(k-1)/2;
        m2=k;
        if (sost==1){
            s1+=max(m1,m2);
        }
        m1=m2;
        k=1;
        c=s0[i];
        sost=1-sost;
      
    }
    if (sost==1){
        s1+=m1;
    }
    cout<<s+s1;
    return 0;
}



