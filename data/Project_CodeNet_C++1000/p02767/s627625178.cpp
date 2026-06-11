#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
pair<int,int> p;
map<int,int> m;
deque<int> d;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int x[n];
for(int i=0;i<n;i++)
    cin>>x[i];
int sum = 0;
for(int i=0;i<n;i++)
    sum += x[i];
float p = float(sum)/float(n);
int sum2 = 0;
for(int i=0;i<n;i++)
    sum2+=pow(x[i]-round(p),2);
cout<<sum2<<endl;
return 0;
}
