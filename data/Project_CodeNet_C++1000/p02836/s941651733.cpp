#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt=0;
    for(int i=0; i<n/2; i++)
    {
        if(s[i]== s[n-i-1])
            continue;
        else
            cnt++;
    }
    cout<<cnt<<endl;
}
