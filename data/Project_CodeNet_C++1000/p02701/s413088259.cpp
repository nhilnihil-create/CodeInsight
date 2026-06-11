#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int Size = ceil(sqrt(N));
	vector<string> table[Size];
	int sum = 0;
	while(N-- > 0){
        string S;
        cin >> S;

        int temp = 0;
        for(int a = 0; a < S.size(); a++){
            temp += S[a] - 'a' + 1;
            temp *= 26;
            temp %= Size;
        }

        int found = false;
        for(int a = 0; a < table[temp].size(); a++){
            if(S.compare(table[temp][a]) == 0){
                found = true;
                break;
            }
        }

        if(!found){
            sum++;
            table[temp].push_back(S);
        }
	}

	cout << sum << endl;
	return 0;
}
