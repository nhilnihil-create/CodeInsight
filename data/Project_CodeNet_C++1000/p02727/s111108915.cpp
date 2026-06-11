#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int> abox,bbox,cbox;
    for(int i=0;i<a;i++){
        int temp;
        cin>>temp;
        abox.push_back(temp);
    }
    for(int i=0;i<b;i++){
        int temp;
        cin>>temp;
        bbox.push_back(temp);
    }
    for(int i=0;i<c;i++){
        int temp;
        cin>>temp;
        cbox.push_back(temp);
    }
    sort(abox.begin(),abox.end());  
    sort(bbox.begin(),bbox.end());  
    sort(cbox.begin(),cbox.end());
    
    vector<int> total_eaten;
    for(int i=0;i<x;i++){
        total_eaten.push_back(abox.back());
        abox.pop_back();
    }
    for(int i=0;i<y;i++){
        total_eaten.push_back(bbox.back());
        bbox.pop_back();
    }
    for(int i=0;i<c;i++){
        total_eaten.push_back(cbox.back());
        cbox.pop_back();
    }
    sort(total_eaten.begin(),total_eaten.end());
    reverse(total_eaten.begin(),total_eaten.end());
    ll sum=0;
    for(int i=0;i<x+y;i++){
        sum+=total_eaten[i];
    }
    
    cout<<sum<<endl;

}