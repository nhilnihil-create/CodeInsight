
    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define FAST ios_base::sync_with_stdio(false);cin.tie(0);
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
    //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
    //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
    //#define MOD         1000000007LL
    #define MAX         1000005
    const ll MOD = 1000000000 + 7;
    
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           int n;
           cin >> n;
           
           vector<int> arr(n);
           
           for(int i = 0 ; i < n ; i++)
           {
               cin >> arr[i];
           }
           
           sort(arr.begin() , arr.end() , greater<int>());
           
           ll sum = arr[0];
           int flag = 0 , k = 1;
           for(int i = 1 ; i < n - 1 ; i++)
           {
               sum += arr[k];
               flag++;
               if(flag == 2)
               {
                   flag = 0;
                   k++;
               }
           }
           
           cout << sum << endl;
        }
    }

