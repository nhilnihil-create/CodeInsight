#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>d(n),k(n);
    map<int,int>values;
    for(int i=0;i<n;i++){
        cin>>d[i];
        k[i]=d[i];
        values[d[i]]++;
    }
    sort(d.begin(),d.end());
    for(int i=0;i<n;i++){
        if(values[d[n-1]]>1)cout<<d[n-1]<<endl;
        else{
            if(k[i]==d[n-1])cout<<d[n-2]<<endl;
            else cout<<d[n-1]<<endl;
        }
    }
    return 0;
}