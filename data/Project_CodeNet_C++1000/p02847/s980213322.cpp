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

int main(){
string week[7]{"SUN", "MON", "TUE", "WED", "THU", "FRI","SAT"};
string str;
  cin>>str;

int i;  
  for(i=0;i<7;i++)
  {
    if(str==week[i])
      break;
  }
  
  cout<<7-i;
}