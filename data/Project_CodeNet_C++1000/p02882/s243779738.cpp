#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
     long double a,b,x,ans;
    
    cin >>a>>b>>x;
    if(x >= a*a*b/2.0){
        ans = (long double)atan(2.0*(a*a*b-x)/(a*a*a))*180.0/M_PI;
    }else{
        ans = 90.000000000000-  (long double)atan((x*2)/(a*b*b))*180.0/M_PI;
    }
    //ans = atan(2*(a*a*b-x)/(a*a*a))*180.0/M_PI;

    cout << fixed << setprecision(15)<< ans << endl;
    
    
    return 0;
    

}