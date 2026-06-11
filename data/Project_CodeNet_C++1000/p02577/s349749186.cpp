#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define MK make_pair
#define PB push_back




int main() {
string s;
cin>>s;
int sum = 0, l = s.size();
for(int i = 0; i < l ; i++){
    sum += (s[i] - '0');
}
if(sum % 9 == 0)
    cout<<"Yes"<<endl;
else
    cout<<"No"<<endl;
    return 0;

}