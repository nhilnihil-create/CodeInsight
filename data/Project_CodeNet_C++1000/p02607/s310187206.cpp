#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <vector>
#include<valarray>
#include<map>
#include <bits/stdc++.h>
#include <utility>
#include<bits/stdc++.h>
using namespace std;

int main()
{
long long n;
cin>>n;
long long a[n];
long long counter=0;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    if(a[i]%2!=0&&i%2!=0)
    {
        counter ++;
    }

}


cout<<counter;
    return 0;
}