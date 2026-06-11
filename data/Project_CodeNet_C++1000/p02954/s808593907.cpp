#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int r = 0;
	int l = 0;
	bool countR = true;
	bool countL = false;
	int idx = 0;
	
	getline(cin, s, '\n');
	int len = s.length();
	int data[len];

	for (int i = 0; i < len; i++){
		data[i]=0;
	}

	for (int i = 0; i < len; i++)
	{
		if(countR){
			if(s[i]=='R'){
				r++;
			}else{
				countR = false;
				countL = true;
				idx = i-1;
				l++;
			}
		}else{
			if(s[i]=='L'){
				l++;
			}else{
				countR = true;
				countL = false;
				
				data[idx]+=(int) r/2;
				data[idx+1]+=(int) r/2;
				if(r%2){
					data[idx]++;
				}

				data[idx] += (int) l/2;
				data[idx+1] += (int) l/2;
				if(l%2){
					data[idx+1]++;
				}

				l = 0;
				r = 1;	
			}
		}
		if(i==len-1){
			data[idx]+=(int) r/2;
			data[idx+1]+=(int) r/2;
			if(r%2){
				data[idx]++;
			}

			data[idx] += (int) l/2;
			data[idx+1] += (int) l/2;
			if(l%2){
				data[idx+1]++;
			}
		}
	}
	for (int i = 0; i < len; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}