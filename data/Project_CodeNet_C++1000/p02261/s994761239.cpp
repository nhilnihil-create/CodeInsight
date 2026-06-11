#include <bits/stdc++.h>
using namespace std;

class card{
public:
	int N;
	vector<int> value;
	vector<char> cha;
	vector<string> init_array;
	vector<string> array;
	vector<string> Barray;
	vector<string> Sarray;


	void set(void){
		cin >> N;
		value.resize(N);
		cha.resize(N);
		init_array.resize(N);
		array.resize(N);
		Barray.resize(N);
		Sarray.resize(N);
		for(int i=0; i<N; i++){
			cin >> init_array[i];
			Barray[i] = init_array[i];
			Sarray[i] = init_array[i];
		}
	}

	void init(void){
		for(int i=0; i<N; i++){
			array[i] = init_array[i];
			value[i] = array[i][1]-'0';
			cha[i] = array[i][0];
		}
	}

	void BubbleSort(void){
		for(int i=0;i<N;i++){
			for(int j=N-1;j>i;j--){
				if(value[j]<value[j-1]){
					swap(value[j],value[j-1]);
					swap(Barray[j],Barray[j-1]);
				}
			}
		}
		for(int i=0; i<N; i++)
			cout << Barray[i] << (i<N-1?" ":"");
		cout << endl;
		cout << "Stable" << endl;
	}

	void SelectionSort(void){
		for(int i=0; i<N; i++){
		bool flag = false;
		int minj = i;
		for(int j=i; j<N; j++){
			if(value[j]<value[minj]){
				minj = j;
				flag=true;
			}
		}
		if(flag==true){
			swap(value[i],value[minj]);
			swap(Sarray[i],Sarray[minj]);
		}
		}
		for(int i=0; i<N; i++)
			cout << Sarray[i] << (i<N-1?" ":"");
		cout << endl;
	}

	void isStable(void){
		for(int i=0;i<N;i++){
			if(Barray[i]!=Sarray[i]){
				cout << "Not stable" << endl;
				return;
			}
		}
		cout << "Stable" << endl;
		return;
	}
};


int main(){
	card c1;
	c1.set();
	c1.init();
	c1.BubbleSort();
	c1.init();
	c1.SelectionSort();
	c1.isStable();
	return 0;
}