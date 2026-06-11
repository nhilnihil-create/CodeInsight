#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int x,y,a,b,c;
    cin >> x>>y>>a>>b>>c;
    int p[a],q[b],r[c];
    pair<int,int> pqr[a+b+c];
    for(int i=0;i<a;i++){
        cin >> p[i];
        pqr[i]=make_pair(p[i],1);
    }
    for(int i=0;i<b;i++){
        cin >> q[i];
        pqr[a+i]=make_pair(q[i],2);
    }
    for(int i=0;i<c;i++){
        cin >> r[i];
        pqr[a+b+i]=make_pair(r[i],3);
    }
    sort(p,p+a);
    reverse(p,p+a);
    sort(q,q+b);
    reverse(q,q+b);
    sort(r,r+c);
    reverse(r,r+c);
    sort(pqr,pqr+a+b+c);
    reverse(pqr,pqr+a+b+c);
    int inda=0,indb=0,indc=0;
    long long int res=0;
    int i=0;
    while(true){
        if(pqr[i].second==1){
            if(inda < x){
                inda++;
                res+=pqr[i].first;
            }
        }else if(pqr[i].second==2){
            if(indb < y){
                indb++;
                res+=pqr[i].first;
            }
        }else{
            res+=pqr[i].first;
            indc++;
        }
        // cout << res<<" "<<pqr[i].second<< endl;
        if(inda+indb+indc==x+y){
            break;
        }
        
        i++;

    }
    cout << res << endl;
    return 0;
}