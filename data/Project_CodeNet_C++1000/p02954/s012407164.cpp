#include<iostream>
#include<string>
using namespace std;
int arr[100005];
int main(){
   string s;
   cin>>s;
   int n=s.length();
    for(int i=0;i<n;i++){
    
        if(s[i]=='R' && s[i+1]=='L'){
            int j=i;
            while(j>=0 && s[j]=='R'){
                if((i-j)%2 == 0){
                    arr[i]++;
                }
                else arr[i+1]++;
                j--;
            }
            j=i+1;
            while(j<=n&&s[j] == 'L'){
                if((j-i)%2 == 1){
                    arr[i+1] ++;
                }
                else arr[i]++;
                j++;
            } 
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}