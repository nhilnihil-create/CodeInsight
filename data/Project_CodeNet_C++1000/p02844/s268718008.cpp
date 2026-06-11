#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;string s;
	cin>>n>>s;
	char number[10]={'0','1','2','3','4','5','6','7','8','9'};
	int ans=0;
	int i[3];
	for(i[0]=0;i[0]<10;i[0]++){
		for(i[1]=0;i[1]<10;i[1]++){
			for(i[2]=0;i[2]<10;i[2]++){
				int count=0;
				for(int j=0;j<s.length();j++){
					if(s[j]==number[i[count]]){
						if(count==2){ans++;break;}
						else{count++;}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
