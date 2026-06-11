    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int n,m,p;
        string s;
        cin>>n>>m;
        vector <int> v(n+1,0),x(n+1,0);
        int pen=0,c=0;
        for (int i=0;i<m;i++){
            cin>>p;
            cin>>s;
            if (s=="WA" && x[p]==0){
                v[p]++;
            }
            else if(s=="AC" && v[p]!=0 && x[p]==0){
                pen+=v[p];
                x[p]=1;
                c++;
            }
            else if (s=="AC" && v[p]==0 && x[p]==0){
                c++;
                x[p]=1;
            }
        }
        cout<<c<<" "<<pen<<endl;
        return 0;
    }