#include<bits/stdc++.h>
#define int    long long

using namespace std;
int32_t main()
{  int k,a,b;
cin >> k >> a >> b;
bool poss=false;
for(int i=a; i<=b; i++)
{ if(i%k==0)
{ poss=true;
break;
}
}
if(poss)
{ cout << "OK" << endl;
}
else
{

    cout << "NG" << endl;
}

    return 0;
}
