#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
int a[500005];

int maxHeapify(int i,int h){
    int l,r,largest;
    l=2*i+1;
    r=2*i+2;
    //if(l>=h&&r>=h)

    if(l<h&&a[l]>a[i])largest=l;
    else largest=i;
    if(r<h&&a[r]>a[largest])largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        maxHeapify(largest,h);
    }
}
void buildMaxheap(int h){
    for(int i=(h-1)/2;i>=0;i--)maxHeapify(i,h);
}
/*void print(vector<int>a){
    for(int i=1;i<a.size();i++){
        cout<<"node "<<i<<": key = "<<a[i]<<", ";
        if(i!=1)cout<<"parent key = "<<a[i/2]<<", ";
        if(2*i+1<a.size()){
            cout<<"left key = "<<a[2*i]<<", right key = "<<a[2*i+1]<<", ";
        }else if(2*i<a.size()){
            cout<<"left key = "<<a[2*i]<<", ";
        }
        cout<<endl;
    }
}*/
int main(){
    int h;
    cin>>h;
    for(int i=0;i<h;i++){
        cin>>a[i];
    }
    buildMaxheap(h);
    rep(i,h)cout<<" "<<a[i];
    cout<<endl;
}
