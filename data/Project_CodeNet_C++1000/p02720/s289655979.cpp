#include <bits/stdc++.h>
using namespace std;
#define     LL      long long int
queue<LL>q;
vector<LL>v;
int main()
{
    LL k,a;
    cin>>k;
    for(int i=1;i<=9;i++){
        q.push(i);
    }
    while(!q.empty()){
        if(v.size()>k) break;
        LL ans=q.front();
        q.pop();
        v.push_back(ans);
        LL bs=ans%10;
        if(bs>0){
            q.push((ans*10)+(bs-1));
        }
        q.push((ans*10)+bs);
        if(bs<9){
            q.push((ans*10)+(bs+1));
        }

    }
    cout<<v[k-1]<<endl;


     return 0;
}
