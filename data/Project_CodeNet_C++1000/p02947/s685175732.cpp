#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    string s;
    long long int cou=1;
    long long int ans=0;
    vector<string>v(n);
    for(int i=0; i<n; i++){
        cin>>s;
        sort(s.begin(),s.end());
        v.at(i)=s;
    }
    sort(v.begin(),v.end());
    for(int j=0; j<n-1; j++){
        if(v.at(j)==v.at(j+1)){
            cou++;
        }else{
            ans+=cou*(cou-1)/2;
            cou=1;
        }
    }
    ans+=cou*(cou-1)/2;
    cout<<ans<<endl;
}
