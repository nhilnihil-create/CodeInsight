#include<iostream>
#include<vector>
using namespace std;

struct card{
	char suit;
	int num;
};

int out_card(vector<card> &A,int n){
	int i;
	for (i=0;i<=n-2;i++){
		cout << A[i].suit << A[i].num <<" ";
	}
	cout << A[n-1].suit << A[n-1].num <<endl;
}

void BubbleSort(vector<card> &A, int n){
	int i,j;
	for (i=0;i<n;i++){
		for (j=n-1;j>i;j--){
			if (A[j].num < A[j-1].num){
				swap(A[j],A[j-1]);
			}
		}
	}
}

void SelectSort(vector<card> &A, int n){
	int i,j,minj;
	for(i=0;i<n;i++){
		minj=i;
		for (j=i;j<n;j++){
			if (A[j].num<A[minj].num){
				minj=j;
			}
		}
		swap(A[i],A[minj]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,i;
	cin >> n;
	
	vector<card> C(n),D(n);
	for (i=0;i<n;i++){
		cin >> C[i].suit >> C[i].num;
		D[i].suit=C[i].suit;
		D[i].num=C[i].num;
	}
	
	SelectSort(C,n);
	BubbleSort(D,n);
	
	out_card(D,n);
	cout << "Stable" <<endl;
	
	out_card(C,n);
	int flag=0;
	for(i=0;i<n;i++){
		if((C[i].suit != D[i].suit)||(C[i].num != D[i].num)){
			flag=1;
		}
	}
	if (!flag){
		cout <<"Stable" <<endl;
	}else{
		cout <<"Not stable" <<endl;
	}
	
	return 0;
}