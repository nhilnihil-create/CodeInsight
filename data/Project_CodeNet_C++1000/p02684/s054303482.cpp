#include <bits/stdc++.h>
using namespace std;
long long n,m,x;

int main()
{
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]--;
    }

    vector<int>mvs,nms(n);
    int cr=0;
    while(1){
        if(nms[v[cr]]){
            cr=v[cr];
            break;
        }

        mvs.push_back(v[cr]);
        cr=v[cr];
        nms[cr]=1;
    }
    int i=0;
    int f=0;
    while(m--){
        if(m==0){
            cout<<mvs[i]+1<<'\n';
            f=1;
            break;
        }
        if(mvs[i]==cr){
            break;
        }

        i++;

    }
    if(f==0){
        int rm=mvs.size()-i;
        cout<<mvs[i+m%rm]+1<<'\n';
    }
    return 0;

}
/***
4 5
3 2 4 1
*/
