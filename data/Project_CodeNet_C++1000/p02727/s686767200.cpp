#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;

    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);
    for(int i=0;i<a;i++){
        cin>>p[i];
    }
    for(int i=0;i<b;i++){
        cin>>q[i];
    }
    for(int i=0;i<c;i++){
        cin>>r[i];
    }

    sort(p.rbegin(),p.rend());
    sort(q.rbegin(),q.rend());
    sort(r.rbegin(),r.rend());
    long long ans=0;
    for(int i=0;i<x;i++){
        ans+=p[i];
    }
    for(int i=0;i<y;i++){
        ans+=q[i];
    }
    int i=0;
    int j=x-1;
    int k=y-1;
    while(i<c){
        if(j<0 && k<0){
            break;
        }else if(j<0){
            if(q[k]<r[i]){
                ans-=q[k];
                ans+=r[i];
                k--;
                i++;
            }else{
                break;
            }
        }else if(k<0){
            if(p[j]<r[i]){
                ans-=p[j];
                ans+=r[i];
                j--;
                i++;
            }else{
                break;
            }
        }else{
            if(p[j]<q[k]){
                if(p[j]<r[i]){
                    ans-=p[j];
                    ans+=r[i];
                    j--;
                    i++;
                }else{
                    break;
                }
            }else{
                if(q[k]<r[i]){
                    ans-=q[k];
                    ans+=r[i];
                    k--;
                    i++;
                }else{
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}