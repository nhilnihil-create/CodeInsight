#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int minPrice( map<int,int> map)
{   int min;
    for(auto it=map.begin();it != map.end();++it )
    {
        if(it==map.begin())
        {
            min =it->second;
        }
       if(it->second < min)
       {
           min =it->second;
       }
    }
    return min;
}
int minPriceKey( map<int,int> map)
{   int min;
    int key;
    for(auto it=map.begin();it != map.end();++it )
    {
        if(it==map.begin())
        {
            min =it->second;
            key =it->first;
        }
       if(it->second < min)
       {
           min =it->second;
           key =it->first;
       }
    }
    return key;
}
int main()
{  map<int,int> fruits;
   int n,k,x,sum =0;
   cin>>n;
   cin>>k;
   for(int i=1 ;i<n+1 ;i++)
   {
       cin>>x;
       fruits[i] = x;
   }
for(int i= 0 ;i<k ;i++)
{
  sum+= minPrice(fruits);
  fruits.erase(minPriceKey(fruits));
}
cout<<sum<<endl;
    return 0;
}
