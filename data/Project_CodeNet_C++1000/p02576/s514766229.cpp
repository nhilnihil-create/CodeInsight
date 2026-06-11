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
int n, x, t;
cin>>n>>x>>t;
int minutes = 0;
while(n > 0)
{
    minutes += t;
    n -= x;
}
cout<<minutes<<endl;
    return 0;

}