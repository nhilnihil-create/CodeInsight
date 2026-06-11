#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;

int main()
{
    int n;
    cin>>n;
    vector<string> s(n);
    map<string,int> m;

    for (int i=0;i<n;i++){
        cin>>s[i];

        m[s[i]]+=1;
    }

    int max=0;
    for (const auto& x:m){
        int v=x.second;
        if(v>max) max=v;
    }
    for (auto i=m.begin();i!=m.end();i++){
        if(i->second==max){
            cout<<i->first<<endl;
        }
    }

    


}