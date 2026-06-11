#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;
map<int , int> mp;
int main()
{

    int n;
    scanf("%d",&n);
    bool q=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        mp[x]++;
        if(mp[x]>1)
            q=1;
    }
    if(!q){
        printf("YES");
    }
    else{
        printf("NO");
    }

}
