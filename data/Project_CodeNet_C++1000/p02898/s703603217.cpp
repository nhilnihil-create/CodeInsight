    #include<bits/stdc++.h>
    #define dbug printf("I am here\n");
    #define Fast ios_base::sync_with_stdio(false); cin.tie(0);
    #define vs            v.size()
    #define ss             s.size()
    #define be            v.begin(),v.end()
    #define pii             pair<int,int>
    #define ll               long long
    #define pb             push_back
    #define mpp            make_pair
    using namespace std;

    int main(){

    ll int a,b,c,d,n,k;
    int tst;
    string s;
    char ch,cc;
    cin>>n>>k;
    int cnt = 0;
    for(int i=0;i<n;i++){
            cin>>a;
        if(a>=k)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
    }
