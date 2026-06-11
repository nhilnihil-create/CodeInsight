#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli k,sum=0,cnt;
    string s,t;
    lli i,j=0;
    cin>>t>>k;
    s=t;
    cnt=0;
    rep(i,1,s.size()){
        if(s[i-1]==s[i]){
            s[i]='0';
            cnt++;
        }
    }
    if(s[0]!=s[s.size()-1]){
        sum=cnt*k;
    }
    else{
        s=t;
        sum=cnt;
        cnt=1;
        s[0]='1';
        rep(i,1,s.size()){
            if(s[i-1]==s[i]){
                s[i]='0';
                cnt++;
            }
        }
        if(t[0]==s[s.size()-1]){
            sum+=cnt*(k-1);
        }
        else{
            lli bef=sum;
            sum+=cnt;
            sum=sum*(k/2);
            if(k%2==1){
                sum+=bef;
            }
        }
    }
    cout<<sum<<endl;
}
