#include <iostream>
#include<string>

using namespace std;

int main(){
        int n,ans=0;
        string s;

        cin>>n>>s;

        for(int i=0; i<1000; i++){
                int ch_digit=0,ch_val=i;
                char ch_num[3];
                ch_num[2]='0'+ch_val%10;
                ch_val/=10;
                ch_num[1]='0'+ch_val%10;
                ch_val/=10;
                ch_num[0]='0'+ch_val%10;
                ch_val/=10;

                for(int j=0; j<n; j++){
                        if(s[j]==ch_num[ch_digit]){
                                ch_digit++;
                        }
                        if(ch_digit==3){
                                ans++;
                                break;
                        }
                }
        }

        cout<<ans<<endl;

        return 0;
}
