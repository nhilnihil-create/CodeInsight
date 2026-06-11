#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020

ll gcd(ll a, ll b){
    
    if(b==0)
        return a;
        
    return gcd(b, a%b);
}
int main(){

ll a,b;
cin>>a>>b;
cout<<(a*b)/gcd(a,b);
}