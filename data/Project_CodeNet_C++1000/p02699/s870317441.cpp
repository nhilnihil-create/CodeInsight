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


    int s,w;
    cin>>s>>w;
    if (w>=s)cout<<"unsafe\n";
    else cout<<"safe\n";

    return 0;
}
