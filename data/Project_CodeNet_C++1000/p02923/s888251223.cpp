#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long a[n];
    priority_queue<int>q;
    for(int i=0;i<n;i++)
    cin>>a[i];
    int count=0;
    for(int i=0;i<n-1;i++){
        int temp;
        if(a[i]>=a[i+1]){
            count++;
            q.push(count);
        }
        else
        count=0;
        
    }
    if(q.empty())
    cout<<"0"<<endl;
    else
    cout<<q.top()<<endl;
}