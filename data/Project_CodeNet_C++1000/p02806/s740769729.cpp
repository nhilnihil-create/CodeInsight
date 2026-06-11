#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s,t;
    std::vector<vector<string>> vec(n,vector<string>(2));
    for (int i=0;i<n;i++) {
        cin>>s>>t;
        vec[i][0]=s;
        vec[i][1]=t;
    }
    int flag=0,sum=0;
    string x;
    cin>>x;
    for (int i=0;i<n;i++) {
        if (flag==0) {
            if (vec[i][0]==x) {
                flag=1;
            }
        } else {
            sum+=stoi(vec[i][1]);
            //cout<<sum<<endl;
        }
    }
    cout<<sum<<endl;
}