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

struct skillup{
    lli cost=N;
    vector<vector<lli>> skill;
    
    skillup(lli n,lli m){
        lli c,a,i,j;
        rep(i,0,n){
            vector<lli> vec;
            cin>>c;
            vec.push_back(c);
            rep(j,0,m){
                cin>>a;
                vec.push_back(a);
            }
            skill.push_back(vec);
        }
    }
    
    lli check(lli x,vector<lli> vec){
        lli i,b=0;
        rep(i,2,vec.size()){
            if(vec[i]<x){
                b=1;
                break;
            }
        }
        return b;
    }
    
    void calculate(lli x,lli n,lli m){
        lli i=1;
        vector<lli> vec;
        rep(i,0,m+2){
            vec.push_back(0);
        }
        queue<vector<lli>> cal;
        cal.push(vec);
        while(cal.size()!=0){
            vec=cal.front();
//            rep(i,0,vec.size()){
//                cout<<vec[i]<<" ";
//            }
//            cout<<endl;
            if(vec[0]<n){
                vec[0]++;
                cal.push(vec);
                rep(i,1,vec.size()){
                    vec[i]+=skill[vec[0]-1][i-1];
                }
                if(check(x,vec)==0){
//                    cout<<"値段は"<<vec[1]<<"円です"<<endl;
                    cost=min(cost,vec[1]);
                }
                else{
                    cal.push(vec);
                }
            }
            cal.pop();
        }
    }
    
    void ans(){
        if(cost==N){
            cost=-1;
        }
        cout<<cost<<endl;
    }
    
};

int main(){
    lli n,m,x;
    cin>>n>>m>>x;
    skillup up(n,m);
    up.calculate(x,n,m);
    up.ans();
}
