#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<iterator>
#include<vector>
#include<map>
#include<utility>
#include<set>
#include<stack>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    long long int n,k,ab;
    cin>>n>>k;
    ab=abs(k-(n%k));
    if(ab>(n%k))cout<<n%k;
    else cout<<ab;

    return 0;
}
