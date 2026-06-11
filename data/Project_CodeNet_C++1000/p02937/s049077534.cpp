#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> c[26];
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    s=s+s;
    for(int i=0;i<s.size();i++){
        c[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<t.size();i++){
        if(c[t[i]-'a'].empty()){
            cout<<-1<<endl;
            return 0;
        }
    }
    long long sum=c[t[0]-'a'][0]+1;
    long long now=c[t[0]-'a'][0];
    for(int i=1;i<t.size();i++){
        long long hoge=*upper_bound(c[t[i]-'a'].begin(),c[t[i]-'a'].end(),now);
        sum+=hoge-now;
        (now=hoge)%=n;
    }
    cout<<sum<<endl;
	return 0;
}