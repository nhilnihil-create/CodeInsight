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
long long a[n+1];
long long sum=0;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}

for(int i=1;i<=n;i++)
{
   if(a[i]%2!=0&&i%2!=0)
   {
       sum ++;
     
   }


}
cout<<sum;
    return 0;
}
