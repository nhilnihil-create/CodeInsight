#include<bits/stdc++.h>

using namespace std;
int main()
{
    map<string,int> mp;
    vector<int> v;
    string s;
    int n;
    cin>>n;int k,sum=0;
    for(int i=0;i<n;i+=1){
        cin>>s>>k;
        v.push_back(k);
        int v = mp[s];
        mp[s] = k;
        sum = sum+mp[s];
    }
    cin>>s;
    int sum1=0;
    for(int j=0;j<v.size();j+=1){
        sum1 = sum1+v[j];
        if(v[j]==mp[s]){
            break;
        }
    }
    cout<<sum-sum1<<endl;


    return 0;
}
