#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int main()
{
  int i,x;
    rep0(i,5){
      cin>>x;
      if(x!=i+1)break;
    }
    cout << i+1 << endl;
    return 0;
}