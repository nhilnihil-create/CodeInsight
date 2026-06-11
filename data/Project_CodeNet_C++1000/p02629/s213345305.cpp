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
#include <utility>
#include <deque>
#include <queue>
using namespace std;

int main()
{
unsigned long long int n;
char c;
string s;
cin>>n;
long long counter=0;
while (n>=26)
{


    if(n%26!=0)
    {
        counter++;
        n--;
    }
     else if(n%26==0&&counter==0)
    {
         s+='z';
         n-=1;
         n/=26;

    }
    else if(n%26==0)
    {


        c =(96+counter);



        s+=c;
        counter=0;
        n/=26;
    }

}

if(n==26)
    s+='a';
else if(n>=1&&n<26) {


    c = (96 + n);
    s += c;
}
reverse(s.begin(),s.end());

cout<<s;


    return 0;
}