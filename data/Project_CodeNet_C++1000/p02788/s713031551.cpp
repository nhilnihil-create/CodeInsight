#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
#include<map>//map
using namespace std;
typedef long long LL; 
typedef pair<LL,LL> P;//Pでpair<-,->を表す。
const LL MAX=2000010;
const LL MOD=1000000007;
typedef map<LL,LL>::iterator Itr;

int main()
{ 
    LL n,d,a;
    cin>>n>>d>>a;
    priority_queue<P,vector<P>,greater<P> > p;
    LL life[n];
    LL attack[n];
    LL sum=0;
    LL ans=0;
    for(int i=0;i<n;i++){
        LL x,h;
        cin>>x>>h;
        life[i]=h;
        p.push(P(x,i));
        p.push(P(x+2*d,n+i));
    }
    while(!p.empty()){
        P q=p.top();
        p.pop();
        //cout<<q.first<<' '<<q.second<<' '<<'k'<<endl;
        LL x=q.second;
        if(x<n){
            if(life[x]>sum){
                if(life[x]%a==0){attack[x]=life[x]-sum;}
                else{attack[x]=a*((life[x]-sum)/a+1);}
                sum=sum+attack[x];
                ans=ans+attack[x]/a;
                //cout<<ans<<' '<<q.first<<' '<<q.second<<endl;
            }
            else{attack[x]=0;}
        }
        else{
            x=x-n;
            sum=sum-attack[x];
        }
    }
    cout<<ans<<endl;
    return 0;
}