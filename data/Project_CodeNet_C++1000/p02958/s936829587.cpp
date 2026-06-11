#include<bits/stdc++.h>
using namespace std;

int main(){
int N;
scanf("%d",&N);
vector<int> A(N);
for(int i=0; i<N; i++){
	scanf("%d",&A[i]);
}
auto sortA = A;
sort(sortA.begin(), sortA.end());

int count = 0;
for(int i=0; i<N;i++){
	if(A[i]!=sortA[i]){
		count++;
	}
}
if(count<=2){
	printf("YES\n");
}else{
	printf("NO\n");
}

	return 0;
}
