#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define long long long
#define filein freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

int main() {
    //filein
    long n,k,c;
    string s;

    cin>>n>>k>>c>>s;
    vector<long> v,v1;
    long count=0;
    long i=0;
    while (count<k){
        while (s[i]=='x')i++;
        v.push_back(i);
        count++;
        i+=(c+1);
    }
    count=0;
    i=n-1;
    while (count<k){
        while (s[i]=='x')i--;
        v1.push_back(i);
        count++;
        i-=(c+1);
    }
    reverse(v1.begin(),v1.end());


    for (long j = 0; j <k ; ++j) {
        if (v[j]==v1[j])
            cout<<v[j]+1<<endl;
    }










}
