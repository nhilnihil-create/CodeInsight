#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
#define bv vector<bool>
using namespace std;
typedef pair<int, int>PA;
using namespace std;
#define MAX  999999
int main(){
    while (true) {
    int n1,n2; cin >> n1>>n2; int sum1 =0 ,sum2 = 0;
        if(!(n1+n2)) break;
        bool check = true;
    vi v1(n1,0); vi v2(n2,0);
    rep(i,n1) {cin >>v1[i];sum1+=v1[i];}
    rep(i,n2) {cin >>v2[i];sum2+=v2[i];}
    int bigger = max(sum1,sum2);
    int mini  = min(sum1,sum2); int ans1 = INF,ans2 = INF;
    rep(i,n1){
        rep(k,n2){
            int temp = abs(v1[i]-v2[k]);
            if(sum1+v2[k]-v1[i] == sum2+v1[i]-v2[k]){
                check = false;
                if(v1[i]+v2[k] < ans1+ans2){ans1 = i; ans2 = k;}
            }
        }
    }
        if(check) cout << -1 << endl;
        else cout << v1[ans1] << " " << v2[ans2] << endl;
        check = true;
    
}

  }