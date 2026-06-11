#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char> v;
pair<int,int> p;
map<int,int> m;
deque<int> d;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int t = ceil(n/1.08);
int y = floor(t*1.08);
if(y==n)
    cout<<t<<endl;
else
    cout<<":("<<endl;
return 0;
}
