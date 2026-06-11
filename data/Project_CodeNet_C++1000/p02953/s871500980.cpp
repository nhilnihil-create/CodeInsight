    #include<bits/stdc++.h>
    #define all(v) v.begin(),v.end()
    using namespace std;
    int main(){
        long long n;
        cin>>n;
        vector<long long> h(n);
        for(auto&&i:h)
            cin>>i;
        for(int i=n-1;i>0;i--){
            if(h[i]==h[i-1]-1){
                h[i-1]--;
            }
			else if(h[i]<h[i-1]){
				cout<<"No"<<endl;
				return(0);
			}
        }
        for(int i=0;i<n-1;i++){
            if(h[i]>h[i+1]){
                cout<<"No"<<endl;
                return(0);
            }
        }
        cout<<"Yes"<<endl;
        return(0);
    }