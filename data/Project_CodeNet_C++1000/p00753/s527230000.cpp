#include <iostream>
using namespace std;

bool IsPrime(int n);
bool BinarySearch(int target, int ar[], int array_num);

int main()
{
	const int MAX_N = 256;
	int n[MAX_N], list[123456/2], listnum=0, max=0, min=123456;
	int i=0, count=0;

	while(i<256){
		cin >> n[i];
		if(n[i] == 0) break;
		if(max<n[i]) max = n[i];
		if(n[i]<min) min = n[i];
		i++;
	}
	if(min==1){
		list[listnum] = 2;
		listnum++;
	}
	for(int j=(min+1)%2==0?min+2:min+1; j<max*2; j+=2){
		if(IsPrime(j)){
			list[listnum]=j;
			listnum++;
		}
	}
	for(int j=0; j<i; j++){
		if(n[j] == 1){
			cout << 1 << endl;
			continue;
		}
		count=0;
		for(int k=((n[j]+1)%2==0)?n[j]+2:n[j]+1; k<=n[j]*2; k+=2){
			if(!BinarySearch(k, list, listnum))continue;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}

bool BinarySearch(int target, int ar[], int array_num)
{
	int L=0, R=array_num-1, M;
	while(L<=R){
		M = (L+R)/2;
		if(ar[M] == target) return true;
		else if(ar[M]<target)L=M+1;
		else R=M-1;
	}
	return false;
}

bool IsPrime(int n){
    int i;
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
    if(n%2 == 0)
        return 0;
    for(i=3; i<=n/i; i+=2)
         if(n%i == 0)
            return false;
    return true;
}