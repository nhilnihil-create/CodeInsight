    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0; i<(n); i++)
    using ll = long long;
    using P = pair<int,int>;
    const int INF = 1001001001;
    int main()
    {
        int n,k,c;
        cin >>n >> k >> c;
        vector<int> right(n),left(n);
        string s;cin >> s;
        int p = 0;
        
        rep(i,n){
            //left
            if (i-c-1 >= 0)p = max(p,left[i-c-1]);
            if(s[i] == 'x')continue;
            
            left[i] = p +1;
        }
        p = 0;
        for(int i = n-1;i >= 0;i--){
            //right
            if(i+ c+ 1 <=n-1)p = max(p,right[i+c+1]);   
            if(s[i] == 'x')continue;
            
            right[i] = p +1;
        }    
        int work = 1;



        vector<int> l(n,-INF),r(n,-INF);
        rep(i,n){
            if(left[i] == work){
                l[i] = work++;
                
            }
            

        }
        work = 1;
        for(int i = n-1; i>= 0;i--){
            if(right[i] == work){
                r[i] = work++;
            }
            
        }
        
        vector<int> ans;
        rep(i,n){
            if(l[i] + r[i] == k+1)ans.push_back(i+1);
        }
        for(auto p:ans)cout << p << endl;

        return 0;
    }