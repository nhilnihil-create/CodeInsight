#include<iostream>
#include<string>
using namespace std;
// 1
//4235
// 6
class Dise {
public:
	Dise();
	//てっぺんは0番
	int DiseNumber[6];
};

Dise::Dise()
{
	//入力
	for (int i = 0; i < 6; i++) {
		cin >> DiseNumber[i];
	}
}

void LengthRotation(int up,int *CopyDise)
{
	if (CopyDise[0] != up) {
		//縦に回す
		for (int i = 1; i <= 3; i++) {
			//縦回転
			swap(CopyDise[0], CopyDise[4]);
			swap(CopyDise[0], CopyDise[5]);
			swap(CopyDise[0], CopyDise[1]);
			if (CopyDise[0] == up) {
				break;
			}
		}
		
		if (CopyDise[0] != up) {
			for (int i = 1; i <= 3; i++) {				
				swap(CopyDise[0], CopyDise[3]);
				swap(CopyDise[0], CopyDise[5]);
				swap(CopyDise[0], CopyDise[2]);
				if (CopyDise[0] == up) {
					break;
				}
			}
		}
	}
}

void SideRotation(int Front, int *CopyDise)
{
	if (CopyDise[1] != Front) {
		for (int i = 1; i <= 3; i++) {
			swap(CopyDise[1], CopyDise[3]);
			swap(CopyDise[1], CopyDise[4]);
			swap(CopyDise[1], CopyDise[2]);
			if (CopyDise[1] == Front) {
				break;
			}
		}
	}	
}

int main()
{
	Dise dise;
	int q, Up, Front, CopyDise[6];

	cin >> q;

	for (int i = 1; i <= q; i++) {
		cin >> Up>>Front;

		//初期化
		for (int i = 0; i < 6; i++) {
			CopyDise[i] = dise.DiseNumber[i];
		}

		//縦
		LengthRotation(Up, CopyDise);
		//横
		SideRotation(Front, CopyDise);
		//結果
		cout << CopyDise[2] << endl;
	}

	return 0;
}
