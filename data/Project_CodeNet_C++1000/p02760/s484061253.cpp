#include <bits/stdc++.h>

using namespace std;

bool marcados[3][3];
int bingo[3][3];
int n,b;


void marcar(int numero) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (numero == bingo[i][j]) {
				marcados[i][j] = true;
				return;
			}
		}
	}
}

bool verificar_linha() {
	for (int i = 0; i < 3; i++) {
		if (marcados[i][0] && marcados[i][1] && marcados[i][2]) {
			return true;
		}	
	}

	return false;
}

bool verificar_coluna() {
	for (int i = 0; i < 3; i++) {
		if (marcados[0][i] && marcados[1][i] && marcados[2][i]) {
			return true;
		}
	} 

	return false;
}

bool verificar_diagonal1() {
	return marcados[0][0] && marcados[1][1] && marcados[2][2];
}

bool verificar_diagonal2() {
	return marcados[0][2] && marcados[1][1] && marcados[2][0];
}

int main() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			marcados[i][j] = false;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> bingo[i][j];
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> b;
		marcar(b);
	}

	if (verificar_linha() || verificar_coluna() || verificar_diagonal1() || verificar_diagonal2()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}
