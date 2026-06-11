 #include <iostream>
using namespace std;
int main(){
	int n , number[101] , i , j ;
	cin >> n ;
	for ( i = 1 ; i<= n ; i ++ ){
		cin >> number[i] ;
	}
	for ( i = n ; i > 1 ; i --){
		cout << number[i] <<" ";
	}
	cout << number[1] << endl ;
}