#include<iostream>
#include <string>
using namespace std;

int main()
{
	string  word; //string型直接代入できる
	char alp[26] = { 0 }; //a~z
	int result[26] = { 0 }; //0~25
	int n;

	//alpにアルファベット格納する
	for (int i = 97; i <= 122; i++)
	{
		alp[i - 97] = i;
	}


	while (getline(cin, word))// getline:空白が入ってても1行分読み込める
	{
		//入力
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
			{
				n = word[i] - 'A';
				result[n]++;
			}
			if (word[i] >= 'a' && word[i] <= 'z')
			{
				n = word[i] - 'a';
				result[n]++;
			}
		}
	}
		//出力
		for (int k = 0; k < 26; k++)
		{
			cout << alp[k] << " " << ":" << " " << result[k] << "\n";
		}

	return 0;

}

