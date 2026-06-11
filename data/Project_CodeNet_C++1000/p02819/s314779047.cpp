#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;
bool check(int n){


for(int i=2;i*i<=n;i++){
    if(n%i == 0)
        return 1;
}
return 0;

}
int main()
{
 int x;
 cin>>x;
 for(int i=x;;i++){
    if(!check(i)){
        cout<<i;
        return 0;
    }
 }
 }
