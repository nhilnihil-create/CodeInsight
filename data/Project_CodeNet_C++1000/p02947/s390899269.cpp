#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
using namespace std;
using std::cout;
#include <algorithm>
#include <map>
int main(){
long long n,m=0;
cin>>n;
map<string,long long>freq;
string x[n];
for(int i=0;i<n;i++)
                    {
cin>>x[i];
sort(x[i].begin(),x[i].end());
                    }
                    for(int i=0;i<n;i++){
                        freq[x[i]]++;
                    }
for(auto i=freq.begin();i!=freq.end();i++)
    m+=(((i->second))*(((i->second)-1)))/2;
                     cout<<m<<endl;
return 0;
            }