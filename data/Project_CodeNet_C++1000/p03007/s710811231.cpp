#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    int N;
    cin >> N;
    queue<int> A,B;
    
    rep(i,N){
        int a;
        cin >> a;
        if(a >= 0) A.push(a);
        else B.push(a);
    }

    vector<pair<int,int>> ans;
    int res = 0;
    
    if(!A.empty() && !B.empty()){
        if(B.size() == 1){
            int a = A.front(),b = B.front();
            while (A.size() > 1) {
                a = A.front(),b = B.front();
                ans.push_back(make_pair(b,a));
                A.pop(),B.pop();
                B.push(b-a);
            }
            a = A.front(),b = B.front();
            ans.push_back(make_pair(a,b));
            A.pop(),B.pop();
            A.push(a-b);
        
            res = A.front();
            
        }else{
            int a = A.front(),b = B.front();
            ans.push_back(make_pair(a,b));
            A.pop();
            B.pop();
            A.push(a-b);
            
            while (B.size() > 1) {
                a = A.front(),b = B.front();
                ans.push_back(make_pair(a,b));
                A.pop(),B.pop();
                A.push(a-b);
            }
            
            if(A.size() > 1){
                while (A.size() > 1) {
                    a = A.front(),b = B.front();
                    ans.push_back(make_pair(b,a));
                    A.pop(),B.pop();
                    B.push(b-a);
                }
                a = A.front(),b = B.front();
                ans.push_back(make_pair(a,b));
                A.pop(),B.pop();
                A.push(a-b);
                
            }else{
                a = A.front(),b = B.front();
                ans.push_back(make_pair(a,b));
                A.pop(),B.pop();
                A.push(a-b);
            }
            
            res = A.front();
        }
        
        
    }else if(A.empty()){
        
        int a = B.front();
        B.pop();
        while (!B.empty()) {
            int b = B.front();
            B.pop();
            if(a > b) A.push(b);
            else{
                A.push(a);
                a = b;
            }
        }
        int c = A.front();
        A.pop();
        ans.push_back(make_pair(a,c));
        a -= c;
        while (!A.empty()) {
            c = A.front();
            A.pop();
            ans.push_back(make_pair(a,c));
            a -= c;
            res = a;
        }
        
        
    }else{
        
        if(N==2){
            int a = A.front();
            A.pop();
            int b = A.front();
            if(a > b){
                ans.push_back(make_pair(a,b));
                res = a-b;
            }
            else{
                ans.push_back(make_pair(b,a));
                res = b-a;
            }
            
        }else{
            
            int a = A.front();
            A.pop();
            while (!A.empty()) {
                int b = A.front();
                A.pop();
                if(a < b) B.push(b);
                else{
                    B.push(a);
                    a = b;
                    
                }
            }
            
            int c = B.front();
            B.pop();
            int k = B.front();
            B.pop();
            ans.push_back(make_pair(a,c));
            a -= c;
            res = a;
            while (!B.empty()) {
                c = B.front();
                B.pop();
                ans.push_back(make_pair(a,c));
                a -= c;
            }
            ans.push_back(make_pair(k,a));
            res = k-a;
        }
        
        
        
    }
    
    
    
    int n = int(ans.size());
    cout << res << endl;
    rep(i,n) cout << ans[i].first << " " << ans[i].second << endl;
    
    return 0;
}

