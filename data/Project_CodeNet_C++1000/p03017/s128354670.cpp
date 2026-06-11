#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

//lli gcd(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    if(x%y==0){
//        return y;
//    }
//    else{
//        return gcd(y,x%y);
//    }
//}
//
//lli lcm(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    return x*y/gcd(x,y);
//}

int main(){
    lli n,a,b,c,d;
    string s,ans="Yes",t;
    lli i,j;
    cin>>n>>a>>b>>c>>d>>s;
    if(s.find("##")!=string::npos){
        if(((s.find("##")>a-1)&&(s.find("##")<c-1))||((s.find("##")>b-1)&&(s.find("##")<d-1))){
            ans="No";
        }
    }
    else{
        if(((b-a)*(d-c))<0){
            if(s.find("...")==string::npos){
                ans="No";
            }
            else{
                t=s.substr(b-2,d-b+3);
                if(t.find("...")==string::npos){
                    ans="No";
                }
            }
        }
    }
    cout<<ans<<endl;
}
