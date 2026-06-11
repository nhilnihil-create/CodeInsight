#include<iostream>
#include<string>
#include<numeric>
#include<vector>
using namespace std;

int out(vector<int> &A,int n){
	int i;
	for (i=0;i<=n-2;i++){
		cout << A[i] <<" ";
	}
	cout << A[n-1] <<endl;
}

int main(){
	ios::sync_with_stdio(false);
	vector<char> C_list;
	char c;
	while(cin >> c){
		C_list.push_back(c);
	}
	
	vector<int> A_list;
	int n=C_list.size();
	int i=0;
	while(i<n){
		char s=C_list[i];
		if (s=='\\'){
			int j=i;
			int A2=1;
			int height=-1;
			while (height<0){
				j++;
				if (j==n){
					break;
				}
				char s2 = C_list[j];
				if (s2=='/'){
					A2+=(-2*height-1);
					height+=1;
				}else if(s2=='\\'){
					A2+=(-2*height+1);
					height-=1;
				}else{
					A2+=(-2*height);
				}
			}
			if (height ==0 ){
				A_list.push_back(A2/2);
				i=j;
			}
		}
		i++;
	}
	int A=accumulate(A_list.begin(),A_list.end(),0);
	cout << A << endl;
	if (A==0){
	cout << 0 << endl;	
	}else{
		int m = A_list.size();
		cout << m <<" ";
		out(A_list,m);
	}
	return 0;
}