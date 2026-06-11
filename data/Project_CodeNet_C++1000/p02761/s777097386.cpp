#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,i=0,j,s,ans[100010],c,nagasa,ou=0,keta;
    cin >> n >> m;
    string z;
    pair<int, int> p[10000];
    for(i=0;i<m;i++)
    {
        cin >> s >> c;
        p[i]=make_pair(s,c);
    }
    for(i=0;i<1000;i++)
    {
        z=to_string(i);
        nagasa=z.size();
        if(nagasa==n)
        {
            for(j=0;j<m;j++)
            {
                if(z[p[j].first-1]-'0'!=p[j].second)
                {
                    ou++;
                    break;
                }
            }
            if(ou==0)
            {
                cout << i << endl;
                return 0;
            }
            ou=0;
        }
    }
    cout << "-1" << endl;
    return 0;

}
